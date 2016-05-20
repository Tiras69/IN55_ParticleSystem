# IN55_ParticleSystem

--------------------- TODO ----------------------------------

1) Calculer la distance des particules a la camera et les ranger dans le bon
ordre histoire d'éviter certain bug d'affichage gênants.

2) Mettre des images paramétriques.

3) faire les autre types D'emmiter (le cône en priorité)

4) débugger l'emission des particules qui me semble etre un peu boisé (il vont que dans 8 directions pour la sphere)

5) prendre en compte l'orientation de la caméra dans les transformations appliqué aux particules

6) faire un ptit controller pour la caméra (Pas obligé mais peu etre sympa pour la presentation)

7) ajouté un peu de gravité (paramétrique peu etre ).

8) Un parseur de fichier Custom, ou on indiquerait les différents paramètre de
notre system de particule et le programme le créerait ! (on assure la moyenne avec ca)

9) peu etre d'autre truc mais on peu pas ya la VI aussi.

-------------------------------------------------------------


Pour que le Projet compile sur windows (donc sur vos machines windows)
il faut que vous rajoutiez le dossier glew-mingw vos bibliothèques windows
(fournis par le prof)

ensuite dans le .pro il y a une ligne a décommenté en enlevant le "#" avant le win32

il faut mettre en commentaire les lignes ou c'est écrit "unix:!macx"

ensuite quand le projet est importé il faut bien vérifier que le working directory est correct sa serait un truc du genre ~/Template/release.

NOTE : Quand vous aurez tous pull le projet prevenez moi j'ajouterai le .pro
au .gitignore .
