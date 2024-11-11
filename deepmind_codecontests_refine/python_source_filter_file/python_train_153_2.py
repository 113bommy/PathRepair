from sys import stdin
# daca linia incepe cu plus, trebuie in lista members sa adaugam un nou membru
def ifAdd(name, members):
       #name.replace('+','') e responsabil ca in lista membrilor, numele la fiecare sa nu vina cu plus in fata
       members.append(name.replace('+',''))

#daca linia incepe cu minus, trebuie sa scoatem din lista members membrul cu numele name
def ifRemove(name, members):
       #name.replace('-','') e responsabil ca in lista membrilor, numele la fiecare sa nu vina cu minus in fata
       members.remove(name.replace('-',''))

#daca linia nu incepe nici cu plus nici cu minus atunci trebuie sa calculam traficul
def countTraffic(line, members):
       #cautam indexul :
       delete = line.find(':')
       #stergem datele care nu ne intereseaza, adica numele celui care tremite si :
       line = line[delete+1::]
       #returnam nr de biti inmultit cu nr membrilor care au primit mesajul
       return (len(line))*len(members)
       

def getFileData():
       #definim lista members care este goala la inceput
       members = []
       #initializam traficul cu 0
       traffic = 0
       for line in stdin:
              #daca primul caracter e + chemam functia ifAdd
              if line[0] == "+":
                     ifAdd(line, members)
              #daca primul caracter e - chemam functia ifRemove
              elif line[0] == '-':
                     ifRemove(line, members)
              #daca nu e nici plus nici minus, adunam traficul
              else:
                     traffic += countTraffic(line, members)
              
       #printam rezultatul
       print(traffic)
getFileData()