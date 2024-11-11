s1 = input();
s2 = input();
i1 = len(s1)-1;
i2 = len(s2)-1;
k = 0;
while (i1 >= 9 and i2 >= 0 and s1[i1] == s2[i2]):
    i1 -= 1;
    i2 -= 1;
    k += 2;
print(len(s1)+len(s2)-k);