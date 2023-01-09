package exercise1;

public class Example1_2
{
    private void displayFileContent(String filename)
    {
        FileInput fileIn = new FileInput(filename);
        while (fileIn.hasNextLine())
        {
            String s = fileIn.nextLine();
            System.out.println(s);
        }
        fileIn.close(); // Always close a file after it has been used.
    }
    private String getFileName()
    {
        Input in = new Input();
        System.out.print("Enter filename: ");
        String filename = in.nextLine();
        return filename;
    }
    public void showFile()
    {
        String filename = getFileName();
        displayFileContent(filename);
        // Could have written displayFileContent(getFileName());
    }
    public static void main(String[] args)
    {
        new Example1_2().showFile();
    }
}
