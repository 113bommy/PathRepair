im, fam = input().split()

ans = str()
for i, el in enumerate(im[:-1]):
    if im[i + 1] >= fam[0]:
        ans = im[:i + 1] + fam[0]
        break

else:
    ans = im + fam[0]

print(ans)
