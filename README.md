# 14.CPP-Module-02

* Polymorphisme ad-hoc = surcharge de fonctions = fonctions même nom, paramètres différents 
* Surcharge d’opérateurs
* Forme canonique

## Surchage d'opérateurs :
```
> Notation préfixe (= fonctionnelle) : + 1 1             (+(1,1) ressemnble à la notation fonctionnelle)  
> Notation infixe (= fonctionnelle) : 1 + 1  
> Notation préfixe (= fonctionnelle) : 1 1 + 
```

### Exemple préfixe avec pls opérations : a * b + c / d = + * a b / c d
```
a + b  -> b = right hand side = rhs
```
### Exemple de surcharge d'op:  
``` c
[nom_class] &operator=( [nom_class] const & rhs);     # opérateur d'assignation
 ```
 
