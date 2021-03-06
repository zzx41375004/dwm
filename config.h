/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 0;     /* 0 means no systray */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
/* static const char *fonts[]          = { "monospace:size=16" }; */
/* static const char dmenufont[]       = "monospace:size=16"; */
/* static const char *fonts[]          = { "SauceCodePro Nerd Font Mono:size=16" }; */
// static const char *fonts[]          = { "Fira Code Nerd Font Mono:size=16" };
static const char *fonts[]          = { "Fira Code Nerd Font Mono, Microsoft YaHei:size=16" };
static const char dmenufont[]       = "Fira Code Nerd Font Mono:size=16";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_green[]       = "#50fa7b";
static const char col_magenta[]     = "#ff6ac1";
static const char col_red[]         = "#ff5c57";
static const char col_black[]       = "#192224";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	/* [SchemeSel]  = { col_gray4, col_red,  col_red  }, */
	// [SchemeSel]  = { col_black, col_red,  col_red  },

    // [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
/* static const char *tags[] = { "\uf120", "\uf7ae", "\uf121", "\uf04b", "\ue62e", "\uf251", "\ue727", "\uf537", "\uf684" }; */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
static const char *tags[] = { "???", "???", "???", "???", "???", "???", "???", "???", "???" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
    { "??????",      monocle },
	{ "??????",      tile },    /* first entry is default */
	/* { "><>",      NULL },    /1* no layout function means floating behavior *1/ */
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *killdwm[]  = { "/home/zzx/dwm/scripts/killdwm.sh", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *browsercmd[]  = { "google-chrome-stable", NULL };
static const char *opacityToggle[]  = { "/home/zzx/dwm/scripts/opacityToggle.sh", NULL };
static const char *screenshot[]  = { "/home/zzx/dwm/scripts/screenshot.sh", NULL };
static const char *lightdown[]  = { "/home/zzx/dwm/scripts/lightdown.sh", NULL };
static const char *lightup[]  = { "/home/zzx/dwm/scripts/lightup.sh", NULL };
static const char *voltoggle[]  = { "/home/zzx/dwm/scripts/vol-toggle.sh", NULL };
static const char *voldown[]  = { "/home/zzx/dwm/scripts/vol-down.sh", NULL };
static const char *volup[]  = { "/home/zzx/dwm/scripts/vol-up.sh", NULL };
static const char *cWallpaper[]  = { "/home/zzx/dwm/scripts/changeWallpaper.sh", NULL };
static const char *touchpadToggle[]  = { "/home/zzx/dwm/scripts/touchpadToggle.sh", NULL };
static const char *colemakToggle[]  = { "/home/zzx/dwm/scripts/colemakToggle", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "80x24", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_k,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_y,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_o,      spawn,          {.v = opacityToggle } },
    { MODKEY,                       XK_t,      spawn,          {.v = touchpadToggle } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_g,      spawn,          {.v = browsercmd } },
    { MODKEY,                       XK_4,      spawn,          {.v = colemakToggle } },
	{ MODKEY,                       XK_F1,     spawn,          {.v = lightdown } },
	{ MODKEY,                       XK_F2,     spawn,          {.v = lightup } },
	{ MODKEY,                       XK_F4,     spawn,          {.v = voltoggle } },
	{ MODKEY,                       XK_F5,     spawn,          {.v = voldown } },
	{ MODKEY,                       XK_F6,     spawn,          {.v = volup } },
	{ MODKEY,                       XK_c,      spawn,          {.v = cWallpaper } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          {.v = killdwm } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = screenshot } },
	{ MODKEY|ShiftMask,             XK_e,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_u,      rotatestack,    {.i = -1 } },
    { MODKEY,                       XK_m,      focusmaster,    {0} },
    { ALTKEY,                       XK_Tab,    focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_e,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_n,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_u,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      focusstack,     {.i = -1 } },
	/* { MODKEY,                       XK_h,      incnmaster,     {.i = +1 } }, */
	/* { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } }, */
	{ MODKEY|ControlMask,           XK_n,      setmfact,       {.f = -0.05} },
	{ MODKEY|ControlMask,           XK_i,      setmfact,       {.f = +0.05} },
	/* { MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
	/* { MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } }, */
	/* { MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
	/* { MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
	/* { MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
	/* { MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
	/* { MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} }, */
	/* { MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, */
	/* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */
	/* { MODKEY,                       XK_+,      zoom,           {0} }, */
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_l,      killclient,     {0} },
	/* { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, */
	//{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	/* { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, */
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	/* { MODKEY|ShiftMask,             XK_j,      viewtoleft,     {0} }, */
	/* { MODKEY|ShiftMask,             XK_l,      viewtoright,    {0} }, */
	{ MODKEY|ShiftMask,             XK_Left,   tagtoleft,      {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagtoright,     {0} },
	TAGKEYS(                        XK_q,                      3)
	TAGKEYS(                        XK_w,                      4)
	TAGKEYS(                        XK_f,                      5)
	TAGKEYS(                        XK_p,                      6)
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	// TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_d,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

