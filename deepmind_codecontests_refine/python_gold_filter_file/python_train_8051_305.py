a = int(input())
b = input().split(" ")
c = [int(i) for i in b]
print(sum(c)/(a*100)*100)