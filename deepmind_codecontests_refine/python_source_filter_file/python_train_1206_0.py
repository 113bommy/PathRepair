x = input()
h = "hiedi"
i = 0
l = len(h)
for a in x:
 #   print(a)
  #  print(h[i])
    if a==h[i]:
        i+=1

    if i ==l:
        break
if i ==l:
    print("NO")
else:
    print("YES")


