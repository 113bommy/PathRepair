a = input()
spisok = ['H', 'Q', 9, '+'] 
ans = 'NO'
for i in range(len(a)):
    if a[i] in spisok:
        ans = 'YES'
print(ans)
    