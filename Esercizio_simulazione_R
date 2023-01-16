set.seed(123456)

dati = read.table("frodi.txt", header = T)

n1 = sample(301:303, 1, replace = F)
I = sample(1:nrow(dati), n1, replace = F)
campione1 = dati[I, ]

#DOMANDA 1
#supponendo che i valori in campione1$tempi provengano da una distribuzione esponenziale, 
#utilizzarli per stimare numericamente con il metodo di massima verosimiglianza il parametro λ 
#e tramite esso calcolare la probabilità p1 di osservare un tempo superiore a 36 

logL = function(lam) length(campione1$tempi)*log(lam)-lam*sum(campione1$tempi)
max
l_hat = optimize(logL, c(1/max(campione1$tempi), 1/min(campione1$tempi)),maximum = TRUE)$maximum
l_hat

prob = 1 - pexp(36, l_hat)
prob

#DOMANDA 2
#supponendo che i valori in campione1$frauds provengano da una distribuzione di Poisson, 
#utilizzarli per stimare il metodo dei momenti il parametro λ e tramite esso calcolare la probabilità p2 
#di osservare un numero di frodi strettamente inferiore alla media dei valori in dati$frauds  [punti 3]

Xs = mean(campione1$frauds)
Xs

media_frauds = mean(dati$frauds)

p2 = ppois(Xs, lambda = media_frauds) - dpois(Xs, lambda = media_frauds)
p2


#DOMANDA 3
#creare un vettore medie di lunghezza 33, contenente le medie aritmetiche di campioni, tutti di ampiezza 100,
#estratti casualmente da dati$tempi e tramite questo vettore medie individuare un intervallo di confidenza al 97% per 
#la media e verificare se esso copra o meno il valore della media di dati$tempi 

medie = numeric(33)

for(i in 1:33){
    medie[i] = mean(sample(dati$tempi, 100))
  }
medie

alpha = 0.03

IC=t.test(medie ,mu = mean(dati$tempi),alternative = "two.sided", conf.level=1-alpha)$conf.int
as.numeric(IC)
(IC[1]<=mean(dati$tempi))&(IC[2]>=mean(dati$tempi))

#DOMANDA 4
#Supponendo che un fenomeno avvenga con probabilità p3= 1-p2, con p2 individuata al punto 2 
#(in caso non si sia svolto il punto 2 prendere per p2 un valore estratto da distribuzione uniforme in [0.5, 0.6]), 
#determinare, individuando un’opportuna distribuzione, con che probabilità in una successione di tentativi 
#indipendenti ed equiprobabili il primo avvenimento si abbia dopo 3 tentativi 


p3 = 1-p2
p3

t = pgeom(3, prob = p3)
t

#estrarre casualmente un valore n2 tra gli interi 601, 602, 603 ;
#estrarre da dati un campione2 di ampiezza n2 [punti 1]


n2 = sample(601:603, 1, replace = F)
n2 
I = sample(1:nrow(dati), n2)
I
campione2 = dati[I, ]




#Creare un vettore x composto dalle classi di appartenenza dei valori di campione2$tempi nelle classi
#[1 , 10] , ] 10 , 22], ] 22 , 44], ]44, 206] 
#e un vettore y composto dalle classi di appartenenza dei valori di campione2$frauds nelle classi
#] 0 , 3], ] 3 , 6] , ]6 , 23] 

estremi_x = c(1, 10, 22, 44, 206)
estremi_x

estremi_y = c(0, 3, 6, 23)
estremi_y

x = cut(campione2$tempi, breaks = estremi_x)
x

y = cut(campione2$frauds, estremi_y)
y

#DOANDA B
#Condurre un test, riportandone la decisione, sull’ipotesi d’indipendenza tra x e y con una significatività dell’ 2% [3 punti];

contingenza = table(x,y) # creazione tabella di contingenza
contingenza

alpha.ind = 0.02 # nuovo valore di significatività

p.value.indip = chisq.test(contingenza)$p.val # estrapolazione p-value
p.value.indip

# regola di decisione 
if (p.value.indip < alpha.ind) print("si rifiuta H0 (i dati NON provengono da v.a. indipendenti)") else print("si accetta H0 (i dati provengono da v.a. indipendenti)")


#DOMANDA C
#Creare un vettore m con 52 valori pari alle medie aritmetiche di campioni, di ampiezza 102 ciascuno,
#estratti casualmente da campione2$frauds e calcolare i valori s2 pari alla varianza campionaria corretta 
#dei valori in m e sigma0.2 pari alla varianza campionaria corretta di campione2$frauds diviso per 102. 
#Con i valori di m condurre un test, riportandone la decisione,  sulla varianza con significatività del 10% 
#con ipotesi nulla H0: σ02= sigma0.2 e ipotesi alternativa come la relazione che avete tra i vostri valori numerici
#di s2 e sigma0.2 (quindi con H1: σ02 < sigma0.2 oppure H1: σ02 > sigma0.2 a seconda della disuguaglianza che avete tra i 
#vostri due valori  s2 e sigma0.2) 

m = numeric(52)

  for(i in 1:52){
    m[i] = mean(sample(campione2$frauds, 102))
  }
m

s2 = var(m)
s2

sigma0.2 = var(campione2$frauds)/102
sigma0.2

#TEST DELLA VARIANZA

alpha = 0.10

n = length(m)

t = (n-1)*s2/sigma0.2 # valore della statistica test 
t

if (s2 > sigma0.2){
  val.critico = qchisq(1 - alpha, df=n-1)
  if (t > val.critico) cat("si RIFIUTA H0") else cat("NON si rifiuta H0")
} else{
  val.critico = qchisq(alpha, df=n-1)
  if (t < val.critico) cat("si RIFIUTA H0") else cat("NON si rifiuta H0")
}
