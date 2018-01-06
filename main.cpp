#include <allegro.h>

void baslat();
void bitir();
void baslangicEkrani();
void islemler();
void cizimRengiIslemler();
void kaydet();
void cizimYukle();
int tiklamaSayisi();

int cizimRengi, beyazRenk;
BITMAP *araKatman;
int degisken, degisken2;
PALETTE p;
BITMAP *dosya;

int ilkx, ilky, ikincix, ikinciy, ucuncux, ucuncuy;

int main()
{
    baslat();

    araKatman = create_bitmap(1260, 700);
    BITMAP *butonlar = load_bitmap("butonlar.bmp", NULL);
    BITMAP *oncekiCizim = load_bitmap("oncekiCizim.bmp", NULL);
    show_mouse(screen);
    baslangicEkrani();

    while(!key[KEY_ESC])
    {
        blit(butonlar, araKatman, 0, 0, 0, 0, 1260, 90);
        blit(oncekiCizim, araKatman, 0, 0, 830, 605, 430, 95);
        release_screen();

        rectfill(araKatman, 0,   600, 350, 700, makeacol(200, 200, 200, 0)); // gri taban
        rectfill(araKatman, 30,  630, 55,  655, makeacol(200, 250, 500, 0)); // buz mavisi
        rectfill(araKatman, 60,  630, 85,  655, makeacol(255, 0,   0,   0)); // kirmizi
        rectfill(araKatman, 90,  630, 115, 655, makeacol(0,   255, 0,   0)); // yesil
        rectfill(araKatman, 120, 630, 145, 655, makeacol(0,   0,   255, 0)); // lacivert
        rectfill(araKatman, 150, 630, 175, 655, makeacol(240, 240, 0,   0)); // sari
        rectfill(araKatman, 180, 630, 205, 655, makeacol(255, 0,   255, 0)); // pembe
        rectfill(araKatman, 210, 630, 235, 655, makeacol(0,   0,   0,   0)); // siyah
        rectfill(araKatman, 240, 630, 265, 655, makeacol(25,  150, 200, 0)); // mavi
        rectfill(araKatman, 270, 630, 295, 655, makeacol(205, 25,  160, 0)); // koyu pembe


        if(mouse_x > 0  && mouse_x < 210 && mouse_y > 0 && mouse_y < 66 && (mouse_b  & 1))
        {
            degisken = 1;
        }

        else if(mouse_x > 210 && mouse_x < 420 && mouse_y > 0 && mouse_y < 66 && (mouse_b & 1))
        {
            degisken = 2;
        }

        else if(mouse_x > 420 && mouse_x < 630 && mouse_y > 0 && mouse_y < 66 && (mouse_b & 1))
        {
            degisken = 3;
        }
        else if(mouse_x > 630 && mouse_x < 840 && mouse_y > 0 && mouse_y < 66 && (mouse_b & 1))
        {
            degisken = 4;
        }
        else if(mouse_x > 840 && mouse_x < 1050 && mouse_y > 0 && mouse_y < 66 && (mouse_b & 1))
        {
            degisken = 5;
        }
        else if(mouse_x > 1050 && mouse_x < 1260 && mouse_y > 0 && mouse_y < 66 && (mouse_b & 1))
        {
            degisken = 6;
        }
        else if(mouse_x > 870 && mouse_x < 1260 && mouse_y > 605 && mouse_y <700 && (mouse_b & 1))
        {
            degisken = 7;
        }
        islemler();




        if(mouse_x > 30 && mouse_x < 55 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 1;
        }
        else if(mouse_x > 60 && mouse_x < 85 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 2;
        }
        else if(mouse_x > 90 && mouse_x < 115 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 3;
        }
        else if(mouse_x > 120 && mouse_x < 145 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 4;
        }
        else if(mouse_x > 150 && mouse_x < 175 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 5;
        }
        else if(mouse_x > 180 && mouse_x < 205 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 6;
        }
        else if(mouse_x > 210 && mouse_x < 235 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 7;
        }
        else if(mouse_x > 240 && mouse_x < 265 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 8;
        }
        else if(mouse_x > 270 && mouse_x < 295 && mouse_y > 630 && mouse_y < 655 && (mouse_b & 1))
        {
            degisken2 = 9;
        }
        cizimRengiIslemler();

        blit(araKatman, screen, 0, 0, 0, 0, 1260, 700); // arakatmandakileri ekrana yukler
    }
    bitir();
    return 0;
}
END_OF_MAIN()

void baslangicEkrani()
{
    clear_to_color(araKatman,makecol(255, 0, 0));
    cizimRengi=makecol(0, 0, 0);
    beyazRenk=makecol(255, 255, 255);
    rectfill(araKatman, 0, 0, 1260, 700, beyazRenk);
}
void baslat()
{
    int res, depth;
    allegro_init();
    depth = desktop_color_depth();
    if(depth == 0)
        depth = 32;
    set_color_depth(depth);

    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1260, 700, 0, 0);
    if(res != 0)
    {
        allegro_message(allegro_error);
        exit(-1);
    }
    install_timer();
    install_keyboard();
    install_mouse();
    set_window_title("Melike AYDIN - Paint");
}
void islemler()
{
    int tiklama = 0;
    tiklamaSayisi();
    tiklama = tiklamaSayisi();
    if(tiklama == 1)
    {
       ilkx = mouse_x;
       ilky = mouse_y;
    }
    else if(tiklama == 2)
    {
        ikincix = mouse_x;
        ikinciy = mouse_y;
    }
    else if(tiklama == 3)
    {
        ucuncux = mouse_x;
        ucuncuy = mouse_y;
    }

    int posilk, posiki, posuc, x1, y1, x2, y2, x3, y3;

    posilk = mouse_pos;
    x1 = posilk >> 16;
    y1 = posilk & 0x0000ffff;

    posiki = mouse_pos;
    x2 = posiki >> 16;
    y2 = posiki & 0x0000ffff;

    posuc = mouse_pos;
    x3 = posuc >> 16;
    y3 = posuc & 0x0000ffff;



    if(degisken == 1 && (mouse_b & 1))
      {
          hline(araKatman, ilkx, ilky, ikincix, cizimRengi);
      }
    else if(degisken == 2 && (mouse_b & 1))
       {
           circlefill(araKatman, mouse_x, mouse_y, 2, cizimRengi);
       }
    else if(degisken == 3 && (mouse_b & 1))
       {
           triangle(araKatman,posilk, mouse_y, posiki, ikinciy, ucuncux, ucuncuy, cizimRengi);
           //triangle(araKatman, mouse_x, mouse_y, mouse_x - 40, mouse_y + 40, mouse_x + 40, mouse_y + 40, cizimRengi);
       }
    else if(degisken == 4 && (mouse_b & 1))
       {
           rect(araKatman, ilkx, ilky, ikincix, ikinciy, cizimRengi);
           //rect(araKatman,mouse_x,mouse_y,mouse_x+100,mouse_y+60,cizimRengi);
       }
    else if(degisken == 5 && (mouse_b & 1))
       {
           circle(araKatman, ilkx, ilky, (ilkx - ilky), cizimRengi);
           //circlefill(araKatman, mouse_x, mouse_y, 20, cizimRengi);
           rest(100);
       }
    else if(degisken == 6 && (mouse_b & 1))
    {
        kaydet();
        exit(-1);
    }
    else if(degisken == 7 && (mouse_b & 1))
    {
        cizimYukle();
    }

}

int tiklamaSayisi() // Bu fonksiyon sayesinde mouse un tiklama sayini bulmaya calistim.
{
    int tik = 0;
    if(mouse_b & 1)
    {
        tik++;
    }
    return tik;
}

void cizimRengiIslemler() // degisken2 ye atadigim degerler sayesinde renk islemlerini yaptiriyorum.
{
    if((getpixel(screen,mouse_x,mouse_y)!= makeacol(200, 200, 200, 0)) && getpixel(screen, mouse_x, mouse_y) != makeacol(255, 255, 255, 0))
    // gri ve beyaza esit degilse girer. Buradaki amacım buton rengini ve arka plan rengini almamasıydı
    {
        if(degisken2 == 1 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
               cizimRengi = makeacol(255, 255, 255, 0);
               cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }
        }
        if(degisken2 == 2 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
               cizimRengi = makeacol(255, 0,   0,   0);
               cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }
        }
        if(degisken2 == 3 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
                cizimRengi = makeacol(0,   255, 0,   0);
                cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }
        }
        if(degisken2 == 4 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
                cizimRengi = makeacol(0,   0,   255, 0);
                cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }
        }
        if(degisken2 == 5 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
                cizimRengi = makeacol(240, 240, 0,   0);
                cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }
        }
        if(degisken2 == 6 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
                cizimRengi = makeacol(255, 0,   255, 0);
                cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }

        }
        if(degisken2 == 7 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
                cizimRengi = makeacol(0,   0,   0,   0);
                cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }

        }
        if(degisken2 == 8 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
                cizimRengi = makeacol(25,  150, 200, 0);
                cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }
        }
        if(degisken2 == 9 && getpixel(screen, mouse_x, mouse_y) != cizimRengi)
        {
            if(mouse_b & 1)
            {
                cizimRengi = makeacol(205, 25,  160, 0);
                cizimRengi = getpixel(screen, mouse_x, mouse_y);
            }
        }
    }
}

void kaydet()
{
    get_palette(p);
    dosya = create_sub_bitmap(screen, 0, 0, SCREEN_W, SCREEN_H);
    save_bitmap("resim.bmp", dosya, p);
    destroy_bitmap(dosya);
}
void cizimYukle()
{
    araKatman = load_bitmap("resim.bmp", p);
}

void bitir()
{
    clear_keybuf();
}
