K = int(input())
Is = [input() for i in range(K)]
Ns = [input() for i in range(K)]
atk_I = 0
atk_N = 0
#"mamoru", "tameru", "kougekida"
#"Isono-kun", "Nakajima-kun", "Hikiwake-kun"
for i, n in zip(Is, Ns):
	i_n = [i, n]
	if (i_n.count("mamoru") == 2):
		pass
	elif (i_n.count("mamoru") == 1):
		if (i_n.count("tameru") == 1):
			exec("atk_{} += 1".format('I' if i[0] == "t" else 'N'))
			if (atk_I > 5):
				atk_I = 5
			elif (atk_N > 5):
				atk_N = 5
		else:
			if (i[0] == "k"):
				if (atk_I == 5):
					print("Isono-kun")
					exit()
				elif (atk_I == 0):
					print("Nakajima-kun")
					exit()
				else:
					atk_I = 0
			elif (n[0] == "k"):
				if (atk_N == 5):
					print("Nakajima-kun")
					exit()
				elif (atk_N == 0):
					print("Isono-kun")
					exit()
				else:
					atk_N = 0
	else:
		if (i_n.count("kougekida") == 2):
			if (atk_I > atk_N):
				print("Isono-kun")
				exit()
			elif (atk_I == atk_N):
				atk_I = 0
				atk_N = 0
			else:
				print("Nakajima-kun")
				exit()
		elif (i_n.count("kougekida") == 1):
			if (i[0] == "k"):
				if (atk_I == 0):
					print("Nakajima-kun")
					exit()
				else:
					print("Isono-kun")
					exit()
			else:
				if (atk_N == 0):
					print("Isono-kun")
					exit()
				else:
					print("Nakajima-kun")
					exit()
		else:
			atk_I += 1 if atk_I != 5 else 0
			atk_N += 1 if atk_N != 5 else 0
else:
	print("Hikiwake-kun")
