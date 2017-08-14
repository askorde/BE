import pprint

data_file = open("data","r+")
data = [x.strip().split() for x in data_file.readlines()]
data.pop(0)
#pprint.PrettyPrinter(	).pprint(data)

work=[]
age=[]
qual=[]
exp=[]

for l in data:
	work.append(l[0])
	age.append(int(l[1]))
	qual.append(l[2])
	exp.append(int(l[3]))
	
#work_p={'Consultancy':0,'Service':0,'Research':0}
work_p={}
for w in work:
	if(w in work_p.keys()):
		work_p[w]=work_p[w]+1
	else:
		work_p[w]=1	
print("work_p\n",work_p)	

#age_p = [<30,>=30]
age_p=[{},{}]
for a,w in zip(age,work):
	if(a<30):
		if(w in age_p[0].keys()):
			age_p[0][w]=age_p[0][w]+1 			
		else:
			age_p[0][w] = 1
	else:
		if(w in age_p[1].keys()):
			age_p[1][w]=age_p[1][w]+1 			
		else:
			age_p[1][w] = 1		

for a in age_p:
	for k in a:
		a[k]=a[k]/work_p[k]
print("age_p\n",age_p)

#qual_p = [<30,>=30]
qual_p=[{},{},{}]
for a,w in zip(qual,work):
	if(a=="Ph.D."):
		if(w in qual_p[0].keys()):
			qual_p[0][w]=qual_p[0][w]+1 			
		else:
			qual_p[0][w] = 1
	elif(a=="MTech."):
		if(w in qual_p[1].keys()):
			qual_p[1][w]=qual_p[1][w]+1 			
		else:
			qual_p[1][w] = 1	
	elif(a=="BTech."):
		if(w in qual_p[2].keys()):
			qual_p[2][w]=qual_p[2][w]+1 			
		else:
			qual_p[2][w] = 1				
for a in qual_p:
	for k in a:
		a[k]=a[k]/work_p[k]

print("qual_p\n",qual_p)

#age_p = [<10,>=10]
exp_p=[{},{}]
for a,w in zip(exp,work):
	if(a<10):
		if(w in exp_p[0].keys()):
			exp_p[0][w]=exp_p[0][w]+1 			
		else:
			exp_p[0][w] = 1
	else:
		if(w in exp_p[1].keys()):
			exp_p[1][w]=exp_p[1][w]+1 			
		else:
			exp_p[1][w] = 1		
for a in exp_p:
	for k in a:
		a[k]=a[k]/work_p[k]

print("exp_p\n",exp_p)
			
			
test = [30,"MTech.",8]
test_p={}

print("Probability values for ",test) 
am=1
qm=1
em=0
for w in work_p:
	test_p[w]=0
	test_p[w]=age_p[am][w]*qual_p[qm][w]*exp_p[em][w]*work_p[w]/len(data)

print(test_p)

for w,p in test_p.items():
	if(p==max(test_p.values())):
		print("\nPredicted Work = ", w)	
