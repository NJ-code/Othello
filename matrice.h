void Coloration(int a, int b)
{

    int r1=0,r2=0,r3=0,r4=0,r5=0,r6=0,r7=0,r8=0;//Permettent de ne pas depasser la case de reference

    for(int i=1;i<8;i++)
    {
//Verification de la ligne
        if(a-i>=0&&M[a-i][b]!='*')
        {
        	if(M[a-i][b]!='*')
        		r1=1;
            if (M[a-i][b]==M[a][b])
            {
                if(r1==0)
                {
                    for(int j=a-i;j<a;j++)
                    {
                        M[j][b]=M[a][b];
                    }
                    r1=1;
                }
            }
        }
        if(a+i<8&&M[a+i][b]!='*')
        {
            if (M[a+i][b]==M[a][b])
            {
                if(r2==0)
                {
                    for(int j=a+1;j<a+i;j++)
                    {
                        M[j][b]=M[a][b];
                    }
                    r2=1;
                }
            }
        }
//Verfication de la colonne
        if(b-i>=0&&M[a][b-i]!='*')
        {
            if (M[a][b-i]==M[a][b])
            {
                if(r3==0)
                {
                    for(int j=b-i;j<b;j++)
                    {
                        M[j][b]=M[a][b];
                    }
                    r3=1;
                }
            }
        }
         if(b+i>8&&M[a][b+i]!='*')
         {
            if (M[a][b+i]==M[a][b])
            {
                if(r4==0)
                {
                    for(int j=b+1;j<b+i;j++)
                    {
                        M[j][b]=M[a][b];
                    }
                    r4=1;
                }
            }
        }
//Verification de la 1ere diagonale
         if(a-i>=0&&b-i>=0&&M[a-i][b-i]!='*')
         {
            if (M[a-i][b-i]==M[a][b])
            {
                if(r5==0)
                {
                    for(int j=1;j<i;j++)
                    {
                        M[a-j][b-j]=M[a][b];
                    }
                    r5=1;
                }
            }
        }
         if(a+i<8&&b+i<8&&M[a+i][b+i]!='*')
        {
            if (M[a+i][b+i]==M[a][b])
            {
                if(r6==0)
                {
                    for(int j=1;j<i;j++)
                    {
                        M[a+j][b+j]=M[a][b];
                    }
                    r6=1;
                }
            }
        }
//Verification de la 2eme diagonale
          if(a-i>=0&&b+i<8&&M[a-i][b+i]!='*')
          {
            if (M[a-i][b+i]==M[a][b])
            {
                if(r7==0)
                {
                    for(int j=1;j<i;j++)
                    {
                        M[a-j][b+j]=M[a][b];
                    }
                    r7=1;
                }
            }
        }
          if(a+i<8&&b-i>=0&&M[a+i][b-i]!='*')
        {
            if (M[a+i][b-i]==M[a][b])
            {
                if(r8==0)
                {
                    for(int j=1;j<i;j++)
                    {
                        M[a+j][b-j]=M[a][b];
                    }
                    r8=1;
                }
            }
        }

    }
}

