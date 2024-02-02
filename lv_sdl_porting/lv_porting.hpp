#pragma once

#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/

#include "lvgl.h"

#include <SDL2/SDL.h>
#include "src/drivers/lv_drivers.h"
#include "lv_demos.h"

class LVGL
{
private:
    uint32_t monitor_hor_res;
    uint32_t monitor_ver_res;
    lv_disp_t *_monitor = nullptr;
    lv_indev_t *_mouse = nullptr;

    static inline int tick_thread(void *data)
    {
        while (1)
        {
            SDL_Delay(5);
            lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
        }

        return 0;
    }

public:
    LVGL(uint32_t hor_res = 480, uint32_t ver_res = 800)
    {
        monitor_hor_res = hor_res;
        monitor_ver_res = ver_res;
    }

    ~LVGL() {}

    void init()
    {
        lv_init();
        _monitor = lv_sdl_window_create(monitor_ver_res, monitor_hor_res);
        _mouse = lv_sdl_mouse_create();
        //SDL Create thread
        SDL_CreateThread(tick_thread, "tick", NULL);
    }

    inline void demo(void)
    {
        // lv_demo_widgets();
        // lv_demo_music();
        lv_demo_benchmark();

    }

    inline void handler(void)
    {
        while (1)
        {
            lv_timer_handler();
            SDL_Delay(5);
        }
        
    }
};
