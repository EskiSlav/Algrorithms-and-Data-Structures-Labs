
public static void hanoiTower(int q, int from, int to, int buffer,int[] discsOnKernel)
    {
        if(q==0) return;
        hanoiTower(q-1,from,buffer,to,discsOnKernel);

        System.out.println("Now: " + discsOnKernel[0] + " "+discsOnKernel[1]+" "+discsOnKernel[2]);
        System.out.println("Removing: "+from + "->" + to);
        
        discsOnKernel[from-1]--;
        discsOnKernel[to-1]++;

        System.out.println("Became: "+discsOnKernel[0]+" "+discsOnKernel[1]+" "+discsOnKernel[2]);
        System.out.println();
        
        hanoiTower(q-1,buffer,to,from,discsOnKernel);
    }