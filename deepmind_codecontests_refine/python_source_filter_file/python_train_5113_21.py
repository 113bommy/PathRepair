chislo_stanzii_S=input()
Lchislo_stanzii_S=[int(t) for t in chislo_stanzii_S.split()]
N=Lchislo_stanzii_S[0]
S=Lchislo_stanzii_S[1]
stanzii_1_vetki=input()
stanzii_2_vetki=input()
Lstanzii_1_vetki=[int(a) for a in stanzii_1_vetki.split()]
Lstanzii_2_vetki=[int(a) for a in stanzii_2_vetki.split()]
if Lstanzii_1_vetki[0] == 0:
    print('NO')
    exit(0)
else:
    if Lstanzii_1_vetki[S-1] and Lstanzii_2_vetki[S-1] ==0:
        print('NO')
        exit(0)
    else:
        if Lstanzii_1_vetki[S-1]==1:
            print('YES')
            exit(0)
        else:
            for j in range(S, N):
                if (Lstanzii_2_vetki[j] == 1 and Lstanzii_1_vetki[j] == 1):
                    print('YES')
                    exit(0)
            print("NO")
#
# else:
#     if Lstanzii_1_vetki[S-1] == 1:
#         print('YES')
#     else:
#         for j in range(S-1,N):
#             if Lstanzii_1_vetki[j] == 1 and Lstanzii_2_vetki[S-1] == 1:
#                 print('YES')
#                 exit(0)
#         print('NO')