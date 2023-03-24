package masc_dat;

import masc_dat.func;
import masc_dat.func.Imposible_Type;

public class players {
    private int GOLDEN_COINS = 0;
    private String PLY_NAME = "";

    public class CURRENCY_HANDLE {
        public CURRENCY_HANDLE() throws Imposible_Type {
            if (hasCoins(16)) {
                throw new func.Imposible_Type("Max value reached.");
            }
        }

        // Modifies the GC value.
        public final int modCoins(final int value) {
            return GOLDEN_COINS = value;
        }

        // Returns the GC value.
        public final double getCoins() {
            return GOLDEN_COINS;
        }

        // Will add more GC.
        public void addCoins(int amount) {
            GOLDEN_COINS += amount;
        }

        // Will remove GC.
        public void delCoins(int amount) {
            GOLDEN_COINS -= amount;
        }

        // Verifies if the ply has x amount of coins.
        public boolean hasCoins(int amount) {
            return GOLDEN_COINS >= amount;
        }
    };

    public class PLAYER_HANDLE {

    };
}
