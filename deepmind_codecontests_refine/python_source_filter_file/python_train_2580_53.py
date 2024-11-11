h=int(input())
w=int(input())
n=int(input())
print(min((h+n-1)//h+1,(w+n-1)//w+1))