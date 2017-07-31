import pprint

data_file = open("data","r+")
data = [x.strip().split() for x in data_file.readlines()]
data.pop(0)
pprint.PrettyPrinter(	).pprint(data)

work=[]
age=[]
qual=[]
exp=[]

for l in data:
	work.append(l[0])
	age.append(int(l[1]))
	qual.append(l[2])
	exp.append(int(l[3]))
	
#age_p={'Consultancy':0,'Service':0,'Research':0}
age_p={}
for w,a in zip(work,age):
	if(w in age_p.keys()):
		age_p[w]=age_p[w]+1
	else:
		age_p[w]=1	
	
print(age_p)			
