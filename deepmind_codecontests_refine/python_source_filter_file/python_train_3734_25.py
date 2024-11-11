w = list(input())
ans= "Yes"
for i in w:
    if w.count(i) != 2:
        ans = "No"
print(ans)