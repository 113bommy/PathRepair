words="010B"
s=""
for word in words:
    if word=="B":
        s=s[:-1]
    else:
        s=s+word
print(s)