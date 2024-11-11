a=int(input())
print("YNeos"[(a//10)%11*(a%1000)%11>0::2])