package masc_dat;

import java.util.Random;

public class func {
    public static class Imposible_Type extends Exception {
        public Imposible_Type(String message) {
            super(message);
        }
    }

    public static final void clearScreen() {
        System.out.print("\r\033[2J\033[H");
    }

    public class rgnGen {
        private static final String[] NAMES = { "Arvaela", "Sylvard", "Baeloria",
                "Zephyrin", "Quinleth", "Orynthea",
                "Xandrielle", "Kaelith", "Thalindor",
                "Vaelstryn", "Myryndor", "Ylvaine",
                "Rythandria", "Eryndelle", "Zaeloria",
                "Arinthea", "Lyvandria", "Orindale",
                "Faeloria", "Neryndor", "sso" };

        // Returns a random value.
        public static final double RandomNumber(double min, double max) {
            return (double) ((Math.random() * (max - min)) + min);
        }

        // Allows will return a random name from the NAMES array.
        public static final String RandonName() {
            Random random = new Random();
            int randomIndex = random.nextInt(NAMES.length);
            return NAMES[randomIndex];
        }
    }
}