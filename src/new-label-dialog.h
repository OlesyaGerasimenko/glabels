/*
 *  new-label-dialog.h
 *  Copyright (C) 2006-2009  Jim Evins <evins@snaught.com>.
 *
 *  This file is part of gLabels.
 *
 *  gLabels is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __NEW_LABEL_DIALOG_H__
#define __NEW_LABEL_DIALOG_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GL_TYPE_NEW_LABEL_DIALOG            (gl_new_label_dialog_get_type ())
#define GL_NEW_LABEL_DIALOG(obj) \
        (G_TYPE_CHECK_INSTANCE_CAST ((obj), GL_TYPE_NEW_LABEL_DIALOG, glNewLabelDialog))
#define GL_NEW_LABEL_DIALOG_CLASS(klass) \
        (G_TYPE_CHECK_CLASS_CAST ((klass), GL_TYPE_NEW_LABEL_DIALOG, glNewLabelDialogClass))
#define GL_IS_NEW_LABEL_DIALOG(obj) \
        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GL_TYPE_NEW_LABEL_DIALOG))
#define GL_IS_NEW_LABEL_DIALOG_CLASS(klass) \
        (G_TYPE_CHECK_CLASS_TYPE ((klass), GL_TYPE_NEW_LABEL_DIALOG))
#define GL_NEW_LABEL_DIALOG_GET_CLASS(obj) \
        (G_TYPE_INSTANCE_GET_CLASS ((obj), GL_TYPE_NEW_LABEL_DIALOG, glNewLabelDialogClass))


typedef struct _glNewLabelDialog         glNewLabelDialog;
typedef struct _glNewLabelDialogClass    glNewLabelDialogClass;

typedef struct _glNewLabelDialogPrivate  glNewLabelDialogPrivate;

struct _glNewLabelDialog
{
	GtkAssistant             parent_instance;

	glNewLabelDialogPrivate *priv;

};

struct  _glNewLabelDialogClass
{
	GtkAssistantClass        parent_class;

        void (*complete) (glNewLabelDialog *this, gpointer user_data);
};


GType      gl_new_label_dialog_get_type              (void) G_GNUC_CONST;

GtkWidget *gl_new_label_dialog_new                   (GtkWindow     *win);

gchar     *gl_new_label_dialog_get_template_name     (glNewLabelDialog *dialog);

void       gl_new_label_dialog_set_template_name     (glNewLabelDialog *dialog,
						      gchar            *name);

void       gl_new_label_dialog_get_filter_parameters (glNewLabelDialog *dialog,
						      gchar           **page_size_id,
						      gchar           **category_id);

void       gl_new_label_dialog_set_filter_parameters (glNewLabelDialog *dialog,
						      const gchar      *page_size_id,
						      const gchar      *category_id);

gboolean   gl_new_label_dialog_get_rotate_state      (glNewLabelDialog *dialog);

void       gl_new_label_dialog_set_rotate_state      (glNewLabelDialog *dialog,
						      gboolean          state);


G_END_DECLS

#endif



/*
 * Local Variables:       -- emacs
 * mode: C                -- emacs
 * c-basic-offset: 8      -- emacs
 * tab-width: 8           -- emacs
 * indent-tabs-mode: nil  -- emacs
 * End:                   -- emacs
 */
