import java.io.*;
import java.util.Scanner;

public class TextEditor {
    static final String FILE_NAME = "text.txt";
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            showMenu();
            try {
                int choice = Integer.parseInt(scanner.nextLine());

                switch (choice) {
                    case 1:
                        writeToFile(scanner);
                        break;
                    case 2:
                        readFromFile();
                        break;
                    case 3:
                        running = false;
                        System.out.println("Редактор завершено.");
                        break;
                    default:
                        System.out.println("Помилка: оберіть пункт від 1 до 3.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Помилка: потрібно ввести число.");
            }

            System.out.println();
        }

        scanner.close();
    }

    public static void showMenu() {
        System.out.println("===== ТЕКСТОВИЙ РЕДАКТОР =====");
        System.out.println("1. Записати до файлу");
        System.out.println("2. Прочитати увесь вміст файлу");
        System.out.println("3. Вийти з редактора");
        System.out.print("Ваш вибір: ");
    }

    public static void writeToFile(Scanner scanner) {
        System.out.print("Введіть рядок для запису: ");
        String text = scanner.nextLine();

        try (FileWriter writer = new FileWriter(FILE_NAME, true)) {
            writer.write(text);
            writer.write(System.lineSeparator());

            System.out.println("Рядок успішно записано до файлу.");
        } catch (IOException e) {
            System.out.println("Помилка під час запису до файлу.");
        }
    }
    public static void readFromFile() {
        File file = new File(FILE_NAME);

        if (!file.exists()) {
            System.out.println("Файл ще не існує.");
            return;
        }

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            boolean hasContent = false;

            System.out.println("===== ВМІСТ ФАЙЛУ =====");

            while ((line = reader.readLine()) != null) {
                System.out.println(line);
                hasContent = true;
            }

            if (!hasContent) {
                System.out.println("Файл порожній.");
            }

            System.out.println("=======================");
        } catch (IOException e) {
            System.out.println("Помилка під час читання файлу.");
        }
    }
}