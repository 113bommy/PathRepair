s = input()
print('Bad' if true in [s[i] is s[i + 1] for i in 3] else 'Good')