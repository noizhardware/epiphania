* filename(not IN the file, the actual name of the file)
  è il nome che comparirà sul link nel menu (gli _ vengono sostituiti con spazi), also "nHw - " viene aggiunto automaticamente per generare il <title> della page
* parent
  è il nome del parent
  home : no parents
* type
  normal : niente di speciale
  index : vuoldire che dopo il contenuto che viene descritto nel .md stesso, verrà messo un elenco di preview di tutti i children
  leaf : la pagina è alla fine dell'albero, non ha children
* theme
  light - dark >> load light.css or dark.css (implement 100r themes?)
* desc
  è la descrizione della pagina corrente, che comparirà nell'index del parent
* status
  active : attivo, verrà renderizzato e indicizzato
  upcoming : verrà indicizzato grayed-out, o strikethru, senza link, la pagina non verrà renderizzata
  unlisted : verrà renderizzata, ma non indicizzata
  hide : non viene renderizzata ne indicizzata

-- this is a comment

---
## C
**PRO**
- easier access to files
- can modify files
- real html pages, indexable
- posso cmq far chiamare il programma in C da node se necessario?
- easy repl con il mio LISP custom (Ducttape Lisp >> .dtlisp)
- posso anche fare un mio linguaggetto veloce per il css

**con**
- re-run each time
- needs dynamic server // build

## js
**PRO**
- fast (modify an .md file >> it's done!)
- embedded in the html ecosystem
- possibly interactive
- edit database natively (requires local node.js)
- can run locally in node with all privileges.
- can be hosted on static server - no builds required

**con**
- cannot access files (.md must be converted!)
- cannot modify files
- node

,,website
,,coding