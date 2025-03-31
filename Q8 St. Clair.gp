set title 'Lake St. Clair - Ice Concentration (2021–2024)'
set xlabel 'Day of the Year'
set ylabel 'Ice Concentration (%)'
set grid
set xrange [0:187]
set yrange [0:100]
set ytics 10
set xtics ("332" 9, "349" 26, "1" 43, "18" 60, "35" 77, "52" 94, "69" 111, "86" 128, "103" 145, "120" 162, "137" 179)



set key top right
set key box

plot 'Lake St. Clair data.txt' using 0:2 with lines title '2021–2022' lc rgb '#0033A0', \
     ''                     using 0:3 with lines title '2022–2023' lc rgb '#FFDD00', \
     ''                     using 0:4 with lines title '2023–2024' lc rgb '#000000'