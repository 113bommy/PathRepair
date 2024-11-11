n,k = map(int, input().split(" "))
s = input()
print(s[0:k-2]+s[k-1].lower()+s[k:-1])