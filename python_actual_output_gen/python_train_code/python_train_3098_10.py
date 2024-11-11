x=int(input())
def f(x):
    if x==0:
        return 0
    elif x==1:
        return 1
    else:
        i=1
        while pow(2,i)<x:
            i+=1
        a=x-pow(2,i-1)
        return 1+f(a)
print(f(x))