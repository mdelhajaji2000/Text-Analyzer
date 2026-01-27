📘 Cahier des charges
Projet : Text Analyzer
1. Contexte et objectif du projet
1.1 Contexte

Le projet Text Analyzer consiste à développer une application capable d’analyser un fichier texte et d’en extraire des statistiques pertinentes (nombre de mots, fréquence, etc.).

Le cœur de l’application sera développé en C++, en s’appuyant sur des structures de données personnalisées (dynamic array, liste chaînée simple) déjà implémentées par l’étudiant.

L’interface utilisateur pourra être :

soit une application console (dans un premier temps),

soit ultérieurement une interface graphique en C#, communiquant avec le cœur C++.

1.2 Objectifs pédagogiques

Ce projet vise à permettre à l’étudiant de :

Passer de l’implémentation de composants isolés à une application complète

Concevoir une architecture logicielle modulaire

Utiliser ses propres structures de données dans un cas réel

Comprendre la notion d’API interne

Apprendre à planifier et structurer un projet logiciel

2. Périmètre du projet (Scope)
2.1 Ce que fait l’application

L’application doit :

Lire un fichier texte depuis le disque

Extraire les mots du texte

Calculer des statistiques :

nombre total de mots

nombre de mots uniques

fréquence de chaque mot

mots les plus fréquents

Afficher les résultats de manière lisible

2.2 Ce que l’application ne fait PAS

Pas de base de données
Pas de réseau
Pas de multithreading
Pas d’optimisation extrême
Pas d’interface graphique obligatoire au début

3. Contraintes techniques
3.1 Langage

C++17 minimum

3.2 Structures de données

Interdiction d’utiliser std::vector, std::list, std::map pour le cœur

Utilisation obligatoire des structures implémentées :

Dynamic Array (vector-like)

Singly Linked List (forward_list-like)

std::string est autorisé.

3.3 Style et qualité

Code lisible et structuré

Séparation claire entre logique métier et interface

Respect de la const-correctness

Pas de logique “tout dans main()”

4. Architecture générale
4.1 Vue d’ensemble
TextAnalyzer/
│
├── core/              ← logique métier (C++)
│   ├── analyzer.hpp
│   ├── analyzer.cpp
│   ├── tokenizer.hpp
│   ├── tokenizer.cpp
│
├── containers/        ← tes structures de données
│   ├── dynamic_array.hpp
│   ├── sList.hpp
│
├── app/               ← application console
│   ├── main.cpp
│
├── tests/             ← tests simples (optionnel)
│
└── README.md

4.2 Description des modules
🔹 containers/

Contient tes structures de données personnelles.
Aucune logique métier ici.

🔹 core/

Cœur du projet.

Responsabilités :

Lecture du texte

Découpage en mots (tokenization)

Calcul des statistiques

Fourniture des résultats sous forme de structures simples

🔹 app/

Point d’entrée de l’application.

Responsabilités :

Interaction avec l’utilisateur

Appel des fonctions du cœur

Affichage des résultats

5. Spécifications fonctionnelles détaillées
5.1 Analyse du texte

Un mot est défini comme :

une suite de caractères alphabétiques (a-z, A-Z)

insensible à la casse (Word == word)

5.2 Statistiques à produire

L’analyse doit produire au minimum :

Nombre total de mots

Nombre de mots uniques

Liste des mots avec leur fréquence

Top N mots les plus fréquents (N configurable)

6. Critères de réussite

Le projet est considéré comme réussi si :

✅ Le code compile sans warnings majeurs
✅ Les structures de données perso sont utilisées
✅ L’application produit des résultats corrects
✅ Le projet est structuré proprement
✅ Le README explique le fonctionnement

7. Évolutions possibles (non obligatoires)

Interface graphique C#

Export des résultats (JSON / TXT)

Analyse de plusieurs fichiers

Optimisation mémoire

8. Conclusion

Ce projet est :

réaliste

formateur

progressif

parfaitement aligné avec ton niveau actuel
