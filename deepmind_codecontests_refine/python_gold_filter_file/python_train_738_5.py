#fisrt divsor of a noumber is always a prime no
#subtracting fist smallest make a noumber even
#once it become even ,n//2
n=int(input());i=2;d=n
while i*i<=n:
 if n%i==0:d=i;break
 i+=1
print(1+(n-d)//2)
