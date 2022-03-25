#СРЕДНЯЯ ЭНЕГР
set terminal png font "Times New Roman,24" size 1000, 1000
set output "E_mid.png"
set ylabel "<E>/N" font "Times New Roman,28"
set xlabel "T" font "Times New Roman,28"
plot 'Complete enumeration.txt' using 1:2 with lines lw 2 title "Complete enumeration", 'Metropolis.txt' using 1:2 with lines lw 2 title "Metropolis", 'Wolf.txt' using 1:2 with lines lw 2 title "Wolf", 'Sw.txt' using 1:2 with lines lw 2 title "Swendsen-Wang"

#СРЕДНЯЯ НАМАГН
set terminal png font "Times New Roman,24" size 1000, 1000
set output "M_mid.png"
set ylabel "<M>/N" font "Times New Roman,28"
set xlabel "T" font "Times New Roman,28"
plot 'Complete enumeration.txt' using 1:3 with lines lw 2 title "Complete enumeration", 'Metropolis.txt' using 1:3 with lines lw 2 title "Metropolis", 'Wolf.txt' using 1:3 with lines lw 2 title "Wolf", 'Sw.txt' using 1:3 with lines lw 2 title "Swendsen-Wang"


#ЧИ
set terminal png font "Times New Roman,24" size 1000, 1000
set output "chi.png"
set ylabel "chi/N" font "Times New Roman,28"
set xlabel "T" font "Times New Roman,28"
plot 'Complete enumeration.txt' using 1:4 with lines lw 2 title "Complete enumeration", 'Metropolis.txt' using 1:4 with lines lw 2 title "Metropolis", 'Wolf.txt' using 1:4 with lines lw 2 title "Wolf", 'Sw.txt' using 1:4 with lines lw 2 title "Swendsen-Wang"


#ТЕПЛОЕМК С
set terminal png font "Times New Roman,24" size 1000, 1000
set output "C.png"
set ylabel "С/N" font "Times New Roman,28"
set xlabel "T" font "Times New Roman,28"
plot 'Complete enumeration.txt' using 1:5 with lines lw 2 title "Complete enumeration", 'Metropolis.txt' using 1:5 with lines lw 2 title "Metropolis", 'Wolf.txt' using 1:5 with lines lw 2 title "Wolf", 'Sw.txt' using 1:5 with lines lw 2 title "Swendsen-Wang"



