# IN55_ParticleSystem

Pour que le Projet compile sur windows (donc sur vos machines windows)
il faut que vous rajoutiez le dossier glew-mingw vos bibliothèques windows
(fournis par le prof)

ensuite dans le .pro il y a une ligne a décommenté en enlevant le "#" avant le win32

il faut mettre en commentaire les lignes ou c'est écrit "unix:!macx"

ensuite quand le projet est importé il faut bien vérifier que le working directory est correct sa serait un truc du genre ~/Template/release.

NOTE : Quand vous aurez tous pull le projet prevenez moi j'ajouterai le .pro
au .gitignore .
