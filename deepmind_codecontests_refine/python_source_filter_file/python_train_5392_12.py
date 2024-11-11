n=int(input())
s=input()
print(["No","Yes"][s[:int(n/2)]]==s[int(n/2):])