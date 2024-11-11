n, x, y = map(int, input("").split(" "))
texte = input("").split("1")
espace = texte.count('')
print(max(0, min((len(texte)-espace-1)*x+y, (len(texte)-espace)*y)))