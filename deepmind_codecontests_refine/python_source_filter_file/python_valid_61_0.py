n = int(input())
for i in range(n):
    tam = int(input())
    seq = input()
    i = 0
    while '?' in seq and i < tam:
        if tam == 1:
            seq = 'B'
        elif 'B' not in seq and 'R' not in seq:
            e = 0
            while '?' in seq:
                seq = seq[:e] + 'B' + seq[e + 1:]
                seq = seq[:e+1] + 'R' + seq[e + 2:]
                e += 2
            if len(seq) > tam:
                seq = seq[:-1]
        elif seq[i] == '?' and i ==  0:
            y = i
            while seq[y] == '?':
                y += 1
            z = 0
            while z<y:
                if y%2 == 1:
                    if seq[y] == 'B':
                        seq = seq[:z] + 'R' + seq[z + 1:]
                        seq = seq[:z+1] + 'B' + seq[z + 2:]
                        z += 1
                    else:
                        seq = seq[:z] + 'B' + seq[z + 1:]
                        seq = seq[:z+1] + 'R' + seq[z + 2:]
                        z += 2
                else:
                    if seq[y] == 'B':
                        seq = seq[:z] + 'B' + seq[z + 1:]
                        seq = seq[:z+1] + 'R' + seq[z + 2:]
                        z += 1
                    else:
                        seq = seq[:z] + 'R' + seq[z + 1:]
                        seq = seq[:z+1] + 'B' + seq[z + 2:]
                        z += 2
        if seq[i] == '?':
            if seq[i-1] == 'B':
                seq = seq[:i] + 'R' + seq[i + 1:]
            elif seq[i-1] == 'R':
                seq = seq[:i] + 'B' + seq[i + 1:]
                
        else:
            i += 1
    print(seq)
        