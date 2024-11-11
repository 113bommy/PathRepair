line1 = [int(x) for x in input().split()];
line2 = [int(x) for x in input().split()];
line3 = [int(x) for x in input().split()];
line4 = [int(x) for x in input().split()];
k = line2[0];
m = line2[1];

if(line3[k-1] < line4[ len(line4) - m] ):
    print("YES");
else:
    print("NO");