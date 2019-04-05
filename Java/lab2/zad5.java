package lab2;

import java.io.IOException;
import java.net.MalformedURLException;
import java.awt.Image;
import java.net.*;
//return getImage(new URL(url,name), name); // tak bybylo chyba poprawnie
public class zad5 {

    /**
     * Description
     * @param url  an absolute URL giving the base location of the image.
     * @param name the location of the image, relative to the url argument.
     * @return the image at the specified URL.
     * @throws IOException if an I/O exception occurs.
     */
    public Image getImage(URL url, String name) throws IOException{
        try {
            // Something to do
            return getImage(new URL(url,name),name);
        }
        catch (MalformedURLException e){
            return null;
        }
    }
}
