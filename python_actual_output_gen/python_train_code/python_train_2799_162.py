ing = list(map(int,input().strip().split()))  # list of input ingredients
print(min(ing[1]*ing[2]//ing[6],ing[3]*ing[4],ing[5]*ing[7])//ing[0])
