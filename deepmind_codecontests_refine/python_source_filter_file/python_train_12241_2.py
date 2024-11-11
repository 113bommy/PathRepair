n = int(input())
brackets = input()
level = 0
lines = [] #status(open - 0, close -1), height
flag =[]
max_level = 0
for i in brackets:
	if i == '[':
		lines.append([0,level])
		level += 1
		if level>max_level:
			max_level = level
	else:
		lines.append([1,level-1])
		level -= 1
		
max_height = (max_level-1) * 2 + 1 + 2
step = [int(i) for i in range(max_level)]
for_print = []

for i in range(n):
	ll = step[-lines[i][1]-1]*2+1+2
	#print('Высота данной скобки без отсутпов',ll)
	if i>0:
		#print('Статус этой и предыущей скобки',lines[i-1][0],lines[i][0],'и их высота',lines[i-1][1],lines[i][1])
		if (lines[i-1][0] + 1 == lines[i][0]) & (lines[i-1][1]  == lines[i][1]): #Если первая скобка отрывающая, вторая - закрывающая и они одного уровня
			#print('Need a margin')
			side = ' '*((max_height-ll)//2)+'-'+' '*(ll-2)+'-'+' '*((max_height-ll)//2)
			for_print.append(side)
			for_print.append(' '*max_height)
			for_print.append(side)
			if i == flag[0]:
				flag.pop(0)
		else:
			if lines[i][0] == 0: #Open
				flag.append(i+1)
			else: #Close
				ll1 = step[-lines[i-1][1]-1]*2+1+2
				new_string = for_print[len(for_print)-1][0:(max_height-ll1)//2-1]+'-'
				#for_print[len(for_print)-1][(max_height-ll1)//2:(max_height-ll1)//2+lines[i-1][1]*2+1]+'-'
				new_string += for_print[len(for_print)-1][(max_height-ll1)//2:(max_height-ll1)//2+step[-lines[i-1][1]-1]*2+3]
				new_string += '-'+ for_print[len(for_print)-1][(max_height-ll1)//2+step[-lines[i-1][1]-1]*2+3+1:len(for_print[len(for_print)-1])]
				for_print[len(for_print)-1] = new_string
	else:
		flag = [i+1] 

		
	s = ''
	if len(flag)>0:
		if i == flag[0]:	
			s += ' '*((max_height-ll)//2-1) #Добавляем нужное число пробелов сверху
			s += '-'
			s += '+'
			s += '|'*(ll-2)
			s += '+'
			s+= '-'
			s += ' '*((max_height-ll)//2-1)			
			flag.pop(0)		
		else:
			s += ' '*((max_height-ll)//2) #Добавляем нужное число пробелов сверху
			s += '+'
			s += '|'*(ll-2)
			s += '+'
			s += ' '*((max_height-ll)//2)
	else:
			s += ' '*((max_height-ll)//2) #Добавляем нужное число пробелов сверху
			s += '+'
			s += '|'*(ll-2)
			s += '+'
			s += ' '*((max_height-ll)//2)			
		

	for_print.append(s)

for i in range(max_height):
	for j in range(len(for_print)):
		print(for_print[j][i],end='')
		#s += for_print[j][i]
	if i != max_height-1:
	    print('\n')

	
