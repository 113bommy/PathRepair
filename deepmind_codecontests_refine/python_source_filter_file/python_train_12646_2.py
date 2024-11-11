n = int(input())
s=input().lower()
print(s)
for i in range(97,123):
    if chr(i) in s:
        a="YES"
    else:
        a="NO"
        break
print(a)