# pre-alpha

* _filename_ (not IN the file, the actual name of the file)
  the name with whic the present page will be displayed on the top menu (`_` are converted to whitespace), also `nHw - ` is automatically prepend to generate the page `<title>`.
* `title` ignored for now?
* **`parent`**
  name of the parent page
  `home` : no parents
* **`type`**
  `normal` : ...normal...
  `index` : after the content described in the file itself, a preview list of all children pages will be displayed.
  `leaf` : a page at the end of the tree, has no children
* **`theme`**
  `light` - `dark` >> load light.css or dark.css
* **`desc`**
  description of the current page, will appear in the parent index
* **`status`**
  `active` : will be rendered and indexed
  `upcoming` : will be indexed grayed-out, or strikethru, without a link, the page will not be rendered. it's a placeholder
  `unlisted` : will be rendered, but not indexed
  `hide` : won't be rendered-indexed
* _comments_
  `-- this is a comment`

<!--
,,site
,,coding
-->