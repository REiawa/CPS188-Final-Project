set title 'Lake Michigan - Daily Ice Concentration (2023-2024)'
set xlabel 'Day of the Year'
set ylabel 'Ice Concentration (%)'
set grid
set xrange [0:158]
set yrange [0:100]
set xtics 20
set ytics 10
set key top right
set key box
set xtics ("342" 13, "354" 25,  "1" 37, "13" 49, "25" 61, "37" 73, "49" 85, "61" 97, "73" 109, "85" 121, "97" 133, "109" 145)

plot 'Question5&6.txt' using 0:3 with lines title 'Lake Michigan' lc rgb '#0033A0'