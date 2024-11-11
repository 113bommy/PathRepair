E='''H	 	He
	Li	Be	 	B	C	N	O	F	Ne
    Na	Mg	 	Al	Si	P	S	Cl	Ar
	K	Ca	 	Sc	Ti	V	Cr	Mn	Fe	Co	Ni	Cu	Zn	Ga	Ge	As	Se	Br	Kr
	Rb	Sr	 	Y	Zr	Nb	Mo	Tc	Ru	Rh	Pd	Ag	Cd	In	Sn	Sb	Te	I	Xe
    Cs	Ba	La	Ce	Pr	Nd	Pm	Sm	Eu	Gd	Tb	Dy	Ho	Er	Tm	Yb	Lu	Hf	Ta	W	Re	Os	Ir	Pt	Au	Hg	Tl	Pb	Bi	Po	At	Rn
	Fr	Ra	Ac	Th	Pa	U	Np	Pu	Am	Cm	Bk	Cf	Es	Fm	Md	No	Lr	Rf	Db	Sg	Bh	Hs	Mt	Ds	Rg	Cn	Nh	Fl	Mc	Lv	Ts	Og
'''.upper().split()
S=input()
N=len(S)
DP=[0]*(N+1)
DP[0]=0
for i in range(N):
  for j in range(1,3):
    if i+j>N:
      break
    if S[i:i+j] in E:
      DP[i+j]|=DP[i]
if DP[N]:
  print('YES')
else:
  print('NO')