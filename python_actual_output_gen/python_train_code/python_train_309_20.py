n, m, z = map (int, input ().split ());
i = 1;
c = 0;
for i in range (0, z + 1, n) :
    if (i == 0) : continue;
    if (i * n % m == 0) : c += 1;
print (c);
