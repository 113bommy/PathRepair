n=int(input())
print("Yes" if (n//10)%111==0 or (n%1000)%111==0 else "No")