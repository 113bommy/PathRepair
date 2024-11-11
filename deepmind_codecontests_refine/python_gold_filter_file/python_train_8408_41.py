i=0
exec('j=-i;exec("i**5-%s-j**5or exit(print(i,j));j+=1;"*i*2);i+=1;'%input()*200)