
pawns,knights,pawnsAllowed,knightsAllowed=[int(i) for i in input().split()]
pawns+=1; knights+=1
infPawns=[[[0 for g in range(pawnsAllowed)] for j in range(knights)] for i in range(pawns)]
infKnights=[[[0 for g in range(knightsAllowed)] for j in range(knights)] for i in range(pawns)]

visited=[[False for j in range(knights)] for i in range(pawns)]

infPawns[1][0][0],infKnights[0][1][0]=1,1


def ans(pawn,knight):
  tempPawn=tempKnight=0
  if pawn>0:
    tempKnight+=sum(infKnights[pawn-1][knight])
  #  print(tempPawn,pawn,knight)
  if knight>0:
   tempPawn+=sum(infPawns[pawn][knight-1])
  if pawn>0:
    for i in range(1,pawnsAllowed):
      infPawns[pawn][knight][i]=infPawns[pawn-1][knight][i-1]
  if knight>0:
    for i in range(1,knightsAllowed):
      infKnights[pawn][knight][i]=infKnights[pawn][knight-1][i-1]
  if knight>0:
    infPawns[pawn][knight][0]=tempKnight
  if pawn>0:
    infKnights[pawn][knight][0]=tempPawn
  
for i in range(pawns):
  for j in range(knights):
    if i+j<=1: continue
    ans(i,j)
    """
for i in range(pawns):
  for j in range(knights):
    
    print(i,j)
    print(infPawns[i][j])
    print(infKnights[i][j])
    print()
    """
print(sum(infPawns[pawns-1][knights-1])+sum(infKnights[pawns-1][knights-1]))