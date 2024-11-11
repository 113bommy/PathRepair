i=0
exec('j=-i;exec("i**5-%s-j**5or exit(print(i,j));j+=1;"*200);i+=1;'%input()*99)