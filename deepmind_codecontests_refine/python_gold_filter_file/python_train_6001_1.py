n, m = map(int, input().split());
A = [];
for q in range(n):
    a = input();
    B = [];
    for w in range(m):
        if a[w] == "S":
            x0 = w;
            y0 = q;
        B.append(a[w])
    A.append(B);
B = [0, 1, 2, 3];
count = 0;
s = input();
#print(x0, y0);
for q in range(4):
    for w in range(4):
        if w == q:
            continue;
        for e in range(4):
            if e == q or e == w:
                continue;
            for r in range(4):
                if r == e or r == w or r == q:
                    continue;
                x = x0;
                y = y0;
                X = [];
                Y = [];
                for i in range(len(s)):
                    mo = int(s[i]);
                    if mo == q:
                        x = x + 1;
                    if mo == w:
                        x = x - 1;
                    if mo == e:
                        y = y + 1;
                    if mo == r:
                        y = y - 1;
                    X.append(x);
                    Y.append(y);
                    if x < 0 or y < 0:
                        #print(q, w, e, r);
                        #print(x, y);
                        #print("HAHA");
                        break;
                    if x >= m or y >= n:
                        #print(q, w, e, r);
                        #print(x, y);
                        #print("OGO");
                        break;
                    #print(x, y);
                    if A[y][x] == "E":
                        #print(x, y);
                        #print(q, w, e, r);
                        #print(*X);
                        #print(*Y);
                        count = count + 1;
                        break;
                    if A[y][x] == "#":
                        #print("ebanyi naxyi");
                        #print(q, w, e, r);
                        #print(x, y);
                        break;
print(count);