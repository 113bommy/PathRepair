x=int(input())
print((x//11)*2 + (0 if x%11==0 else (1 if 11*(x//11)+6>=x else 2)))