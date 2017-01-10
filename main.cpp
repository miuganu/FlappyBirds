void pipes()
    int x,y,r;
    if(timp==10)
    {
        r=(rand()%11)+5;
        for(y=0;y<24;y++)
        {
            afisaj[29][y]='|';
            verifica[29][y]=2;
        }
        afisaj[29][r-1]=' ';
        afisaj[29][r]=' ';
        afisaj[29][r+1]=' ';
        verifica[29][r-1]=0;
        verifica[29][r]=0;
        verifica[29][r+1]=0;
        timp=0;
        goto deplasare;
    }
    else goto deplasare;
    deplasare:
    {
        for(y=0;y<24;y++)
        {
            for(x=0;x<30;x++)
            {
                if(afisaj[x][y]=='|')
                {
                    if(x>0)
                    {
                        afisaj[x-1][y]='|';
                        verifica[x-1][y]=2;
                        afisaj[x][y]=' ';
                        verifica[x][y]=0;
                    }
                    if(x==0)
                    {
                        afisaj[x][y]=' ';
                        verifica[x][y]=0;
                    }
                }
            }
        }
    }
}

void bird()
{
    int x,y;
    if(tasta>0)
    {
        cadere=0;
        for(y=0;y<24;y++)
        {
            for(x=0;x<30;x++)
            {
                if(afisaj[x][y]=='*')
                {
                    if(y>0)
                    {
                    afisaj[x][y-1]='*';
                    afisaj[x][y]=' ';
                    birdx=x;
                    birdy=y-1;
                    return;
                    }
                }
            }
        }
    }
    else
    {
        cadere++;
        for(y=0;y<24;y++)
        {
            for(x=0;x<30;x++)
            {
                if(afisaj[x][y]=='*')
                {
                    if(y<24)
                    {
                        if(cadere<3)
                        {
                            afisaj[x][y+1]='*';
                            afisaj[x][y]=' ';
                            birdx=x;
                            birdy=y+1;
                            return;
                        }
                        else if(cadere>2 && cadere<5)
                        {
                            afisaj[x][y+2]='*';
                            afisaj[x][y]=' ';
                            birdx=x;
                            birdy=y+2;
                            return;
                        }
                        else if(cadere>4)
                        {
                            afisaj[x][y+3]='*';
                            afisaj[x][y]=' ';
                            birdx=x;
                            birdy=y+3;
                            return;
                        }
                    }
                    else
                    {
                        return;
                    }
                }
            }
        }
    }
}
