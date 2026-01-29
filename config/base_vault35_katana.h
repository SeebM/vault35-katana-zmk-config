#include "keys_de.h"
#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/outputs.h>

#define APT 0
#define NAV 1
#define NUM 2
#define SYM 3
#define MED 4

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
  macros {
  macro_sch:
    macro_sch {
      label = "Macro_sch";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <&macro_tap &kp S &macro_release &kp RSHIFT &macro_tap &kp C &kp H>;
    };
  macro_ion:
    macro_ion {
      label = "Macro_ion";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <&macro_tap &kp I &macro_release &kp RSHIFT &macro_tap &kp O &kp N>;
    };
  };
};

#define COMBO(NAME, BINDINGS, KEYPOS) \
  combo_##NAME {                      \
    timeout-ms = <20>;                \
    bindings = <BINDINGS>;            \
    key-positions = <KEYPOS>;         \
  };

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(q, &kp Q, 2 3)
        COMBO(z, &kp DE_Z, 21 22)
        COMBO(v, &kp V, 1 2)
        COMBO(b, &kp B, 12 3)
        COMBO(k, &kp K, 12 13)
        COMBO(x, &kp X, 16 17)
        COMBO(j, &kp J, 6 17)
        COMBO(sch, &macro_sch, 11 13)
        COMBO(ion, &macro_ion, 9 16 18)
        COMBO(_sz, &kp DE_SZ, 35 11)
        COMBO(_ue, &kp DE_UE, 35 8)
        COMBO(_ae, &kp DE_AE, 35 17)
        COMBO(_oe, &kp DE_OE, 35 9)
        COMBO(ent, &kp ENTER, 27 28)
        COMBO(esc, &kp ESC, 23 24)
/* caps */
        COMBO(capsword, &caps_word, 13 16)
        COMBO(capslock, &kp CAPSLOCK, 0 9)
/* deletion */
        COMBO(bspc, &kp BSPC, 6 7)
        COMBO(del, &kp DEL, 7 8)
        COMBO(bspcword, &kp LC(BSPC), 6 8)

    };
};


/ {
    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <170>;
            quick-tap-ms = <150>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 30 32 33 34 35 36 37>;
			hold-trigger-on-release;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <170>;
            quick-tap-ms = <200>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 30 32 33 34 35 36 37>;
			hold-trigger-on-release;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <170>;
            quick-tap-ms = <200>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29>;
        };
    };

};
