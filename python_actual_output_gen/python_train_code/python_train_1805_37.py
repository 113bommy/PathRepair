n = int(input());

v = [];
for word in input().split():
    v.append(int(word));

v.append(0);

maxLength = 1;
curLength = 0;
for i in range(n-1):
    if 2*v[i] >= v[i+1]:
        curLength += 1;
        maxLength = max(maxLength, curLength);
    else:
        curLength = 0;


print(maxLength+1);